#include "config.hpp"

void settings::to_json(json& j, const netvar& n) {
	j = json{
		{"table", n.table},
		{"prop", n.prop},
		{"name", n.name},
		{"offset", n.offset}
	};
}

void settings::from_json(const json& j, netvar& n) {
	j.at("table").get_to(n.table);
	j.at("name").get_to(n.name);
	j.at("prop").get_to(n.prop);
	if (const auto iter = j.find("offset"); iter != j.end()) {
		iter->get_to(n.offset);
	} else {
		n.offset = 0;
	}
}

void settings::to_json(json& j, const signature& s) {
	j = json{
		{"name", s.name},
		{"pattern", s.pattern},
		{"extra", s.extra},
		{"relative", s.relative},
		{"module", s.module},
		{"offsets", s.offsets}
	};
}

void settings::from_json(const json& j, signature& s) {
	j.at("name").get_to(s.name);
	j.at("pattern").get_to(s.pattern);
	j.at("extra").get_to(s.extra);
	j.at("relative").get_to(s.relative);
	j.at("module").get_to(s.module);
	j.at("offsets").get_to(s.offsets);
}
