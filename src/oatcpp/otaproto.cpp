#include <iostream>

#include "fmt/format.h"
#include "oatpp-protobuf/Object.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "src/oatcpp/point.pb.h"

void ProtoDes() {
  dispatch::Geo geo;
  auto des = geo.GetDescriptor();
  auto ref = geo.GetReflection();
  auto point = new dispatch::Point();
  point->set_x(290.9);
  point->set_y(1290.9);
  fmt::println("---------------------------------------");

  fmt::println("type {}", geo.GetTypeName());
  fmt::println("full name {}", des->full_name());
  fmt::println("name {}", des->name());
  fmt::println("{}", des->DebugString());
  ref->SetString(&geo, des->FindFieldByName("name"), "jki");
  // ref->SetAllocatedMessage(&geo , point, des->FindFieldByName("point"));
  // geo.set_allocated_point(point);
  geo.mutable_point()->set_x(90.69);
  auto p2 = std::unique_ptr<dispatch::Point>(geo.release_point());

  fmt::println("{}", geo.DebugString());
  fmt::println("point {}", p2->DebugString());
  auto pdes = des->FindFieldByName("point");
  fmt::println("type {}", int(pdes->type()));
  switch (pdes->type()) {
    case google::protobuf::FieldDescriptor::TYPE_MESSAGE: {
      fmt::println("proto message");
      auto pp2 = ref->MutableMessage(&geo, pdes);
      auto ppdes = pp2->GetDescriptor();
      auto ppref = pp2->GetReflection();
      ppref->SetDouble(pp2, ppdes->FindFieldByName("x"), 5936.9);
      ppref->SetDouble(pp2, ppdes->FindFieldByName("y"), 15888.9);
      break;
    }
    case google::protobuf::FieldDescriptor::TYPE_DOUBLE:
      fmt::println("proto double");
      break;
    default:
      break;
  }
  fmt::println("{}", geo.DebugString());
}

int main(int argc, char* argv[]) {
  oatpp::base::Environment::init();
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount()
            << "\n";
  std::cout << "objectsCreated = "
            << oatpp::base::Environment::getObjectsCreated() << "\n\n";
  oatpp::protobuf::Object<dispatch::Geo> geo =
      std::make_shared<dispatch::Geo>();
  geo->set_name("base");
  auto req = geo->mutable_point();
  req->set_x(20.03);
  req->set_y(90.03);
  oatpp::parser::json::mapping::ObjectMapper mapper;

  {
    auto config = mapper.getSerializer()->getConfig();
    config->enabledInterpretations = {"protobuf"};
    // config->useBeautifier = true;
  }
  {
    auto config = mapper.getDeserializer()->getConfig();
    config->enabledInterpretations = {"protobuf"};
  }
  auto json1 = mapper.writeToString(geo);
  fmt::println("json1={}", json1->c_str());

  auto clone =
      mapper.readFromString<oatpp::protobuf::Object<dispatch::Geo>>(json1);
  clone->set_name("clone");

  auto json2 = mapper.writeToString(clone);
  fmt::println("json2={}", json2->c_str());
  oatpp::base::Environment::destroy();

  ProtoDes();
  int init = 0;
  auto cal =[&]() {
    fmt::println("init ", init);
  };
  
  return 0;
}