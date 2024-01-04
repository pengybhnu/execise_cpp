#include <fstream>
#include <sstream>

#include "cereal/archives/adapters.hpp"
#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/memory.hpp"
#include "cereal/types/unordered_map.hpp"
#include "cereal/types/unordered_set.hpp"
#include "fmt/format.h"
#include "fmt/ranges.h"

struct MyRecord {
  uint8_t x, y;
  float z;

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z));
  }
};
uint32_t version = 1;
struct MyRecordNew {
  uint8_t x, y;
  float z;
  float m;
  // template <class Archive>
  // void serialize(Archive& ar) {
  //   ar(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z), CEREAL_NVP(m));
  // }
  // template <class Archive>
  // void serialize(Archive& archive) {
  //    if (version >0) {
  //     archive(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z), CEREAL_NVP(m));
  //     std::cout << "Version 1" << std::endl;
  //   } else if (version == 0) {
  //     archive(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z));
  //     std::cout << "Version 0" << std::endl;
  //   }
  // }
  template <class Archive>
  void save(Archive& archive,std::uint32_t ver) const {
      std::cout << "save Ver " << ver << std::endl;
    archive(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z), CEREAL_NVP(m));
  }

  template <class Archive>
  void load(Archive& archive,std::uint32_t ver) {
    static uint32_t version{1};
      std::cout << "load Ver " << ver << std::endl;

    if (version > 0) {
      --version;
      std::cout << "Version 1" << std::endl;

      archive(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z), CEREAL_NVP(m));
    } else if (version == 0) {
      std::cout << "Version 0" << std::endl;

      archive(CEREAL_NVP(x), CEREAL_NVP(y), CEREAL_NVP(z));
    }
  }
  // static uint32_t version;
};
#include <fmt/format.h>

template <>
class fmt::formatter<MyRecord> {
  // format specification storage
  char presentation_ = 'f';

 public:
  // parse format specification and store it:
  constexpr auto parse(format_parse_context& ctx) {
    auto i = ctx.begin(), end = ctx.end();
    return i;
  }

  // format a value using stored specification:
  template <typename FmtContext>
  constexpr auto format(MyRecord const& p, FmtContext& ctx)
      const {  // note: we can't use ternary operator ':' in a constexpr
    return format_to(ctx.out(), "({0}, {1}, {2})", p.x, p.y, p.z);
  }
};

template <>
class fmt::formatter<MyRecordNew> {
  // format specification storage
  char presentation_ = 'f';

 public:
  // parse format specification and store it:
  constexpr auto parse(format_parse_context& ctx) {
    auto i = ctx.begin(), end = ctx.end();
    return i;
  }

  // format a value using stored specification:
  template <typename FmtContext>
  constexpr auto format(MyRecordNew const& p, FmtContext& ctx)
      const {  // note: we can't use ternary operator ':' in a constexpr
    return format_to(ctx.out(), "({0}, {1}, {2},{3})", p.x, p.y, p.z, p.m);
  }
};
// struct SomeData {
//   int32_t id;
//   std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data;

//   //   template <class Archive>
//   //   void save(Archive& ar) const {
//   //     ar(id, data);
//   //   }

//   //   template <class Archive>
//   //   void load(Archive& ar) {
//   //     // static int32_t idGen = 0;
//   //     // id = idGen++;
//   //     ar(id, data);
//   //   }

//   template <class Archive>
//   void serialize(Archive& ar) {
//     ar(CEREAL_NVP(id), CEREAL_NVP(data));
//     // ar(id, data);
//   }
// };

int main() {
  // {
  //   // std::ofstream os("out.cereal", std::ios::binary);
  //   std::stringstream os;
  //   cereal::BinaryOutputArchive archive(os);
  //   auto rc = std::make_shared<std::unordered_map<uint32_t, MyRecord>>();
  //   rc->emplace(20, MyRecord{1, 2, 3});
  //   rc->emplace(56, MyRecord{18, 21, 73});

  //   SomeData myData{193, rc};
  //   archive(myData);
  //   fmt::println("data size {}", os.str().size());
  //   std::ofstream osjson("out_cereal.json", std::ios::out);
  //   std::stringstream os2;
  //   cereal::JSONOutputArchive archive2(os2);
  //   cereal::JSONOutputArchive archivejson(osjson);
  //   archive2(myData);
  //   archivejson(myData);
  //   fmt::println("json\n {}", os2.str());
  //   // std::ofstream osxml("out_cereal.xml", std::ios::out);
  //   std::stringstream osxml;
  //   cereal::JSONOutputArchive archiveosxml(osxml);
  //   archiveosxml(myData);
  //   fmt::println("xml\n {}", os2.str());

  // }
  // {
  //   std::ifstream os("out.cereal", std::ios::binary);
  //   std::ifstream os2("out.cereal", std::ios::binary);
  //   cereal::BinaryInputArchive input(os);
  //   cereal::BinaryInputArchive input2(os2);
  //   SomeData inputdata2, inputdata;
  //   input2(inputdata2);
  //   input(inputdata);
  //   fmt::println("{}", inputdata.id);
  //   fmt::println("{}", *(inputdata.data));
  // }
  // {
  //   std::ifstream os("out_cereal.json", std::ios::in);
  //   std::ifstream os2("out_cereal.json", std::ios::in);
  //   cereal::JSONInputArchive input(os);
  //   cereal::JSONInputArchive input2(os2);
  //   SomeData inputdata2, inputdata;
  //   input2(inputdata2);
  //   input(inputdata);
  //   fmt::println("json {}", inputdata.id);
  //   fmt::println("json {}", *(inputdata.data));
  // }
  {
    fmt::println(">>>>>>>>>>><<<<<<<--------------");
    MyRecordNew mr2{14, 5, 6, 7};
    MyRecordNew mr22;
    MyRecord mr1{1, 2, 3};
    MyRecord mr11;
    fmt::println("{}", mr1);
    std::stringstream os2;
    cereal::BinaryOutputArchive output(os2);
    output(mr1);
    std::string str = os2.str();
    fmt::println("size {}", str.size());

    try {
      cereal::BinaryInputArchive archive2(os2);
      archive2(mr22);
      fmt::println("{}", mr22);
    } catch (cereal::Exception& e) {
      fmt::println("!!!exception {}", e.what());
      // version = 0;
      std::stringstream oss;
      oss << str;
      fmt::println("size {}", oss.str().size());
      cereal::BinaryInputArchive archive2(oss);
      archive2(mr22);
      mr22.m = 2000.0;
      fmt::println("{}", mr22);
    }
    fmt::println("###########");
  }
  return 0;
}
