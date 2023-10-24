#include <fstream>
#include <sstream>

#include "cereal/archives/binary.hpp"
#include "cereal/archives/json.hpp"
#include "cereal/archives/xml.hpp"
#include "cereal/archives/adapters.hpp"
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
#include <fmt/format.h>

template <>
class fmt::formatter<MyRecord> {
  // format specification storage
  char presentation_ = 'f';

 public:
  // parse format specification and store it:
  constexpr auto parse(format_parse_context& ctx) {
    auto i = ctx.begin(), end = ctx.end();
    // if (i != end && (*i == 'f' || *i == 'e')) {
    //   presentation_ = *i++;
    // }
    // if (i != end && *i != '}') {
    //   throw format_error("invalid format");
    // }
    return i;
  }

  // format a value using stored specification:
  template <typename FmtContext>
  constexpr auto format(MyRecord const& p, FmtContext& ctx)
      const {  // note: we can't use ternary operator ':' in a constexpr
    return format_to(ctx.out(), "({0}, {1}, {2})", p.x, p.y, p.z);
  }
};

struct SomeData {
  int32_t id;
  std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data;

  //   template <class Archive>
  //   void save(Archive& ar) const {
  //     ar(id, data);
  //   }

  //   template <class Archive>
  //   void load(Archive& ar) {
  //     // static int32_t idGen = 0;
  //     // id = idGen++;
  //     ar(id, data);
  //   }

  template <class Archive>
  void serialize(Archive& ar) {
    ar(CEREAL_NVP(id), CEREAL_NVP(data));
    // ar(id, data);
  }
};

int main() {
  {
    // std::ofstream os("out.cereal", std::ios::binary);
    std::stringstream os;

    cereal::BinaryOutputArchive archive(os);
    auto rc = std::make_shared<std::unordered_map<uint32_t, MyRecord>>();
    rc->emplace(20, MyRecord{1, 2, 3});
    rc->emplace(56, MyRecord{18, 21, 73});

    SomeData myData{193, rc};
    archive(myData);
    fmt::println("data size {}", os.str().size());
    std::ofstream osjson("out_cereal.json", std::ios::out);
    std::stringstream os2;
    cereal::JSONOutputArchive archive2(os2);
    cereal::JSONOutputArchive archivejson(osjson);
    archive2(myData);
    archivejson(myData);
    fmt::println("json\n {}", os2.str());
    // std::ofstream osxml("out_cereal.xml", std::ios::out);
    std::stringstream osxml;
    cereal::JSONOutputArchive archiveosxml(osxml);
    archiveosxml(myData);
    fmt::println("xml\n {}", os2.str());

  }
  {
    std::ifstream os("out.cereal", std::ios::binary);
    std::ifstream os2("out.cereal", std::ios::binary);
    cereal::BinaryInputArchive input(os);
    cereal::BinaryInputArchive input2(os2);
    SomeData inputdata2, inputdata;
    input2(inputdata2);
    input(inputdata);
    fmt::println("{}", inputdata.id);
    fmt::println("{}", *(inputdata.data));
  }
  {
    std::ifstream os("out_cereal.json", std::ios::in);
    std::ifstream os2("out_cereal.json", std::ios::in);
    cereal::JSONInputArchive input(os);
    cereal::JSONInputArchive input2(os2);
    SomeData inputdata2, inputdata;
    input2(inputdata2);
    input(inputdata);
    fmt::println("json {}", inputdata.id);
    fmt::println("json {}", *(inputdata.data));
  }
  return 0;
}
