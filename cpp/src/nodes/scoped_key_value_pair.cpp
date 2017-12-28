#include "scoped_key_value_pair.hpp"

ScopedKeyValuePair::ScopedKeyValuePair(NodePtrs pairs) : pairs(pairs) {}

std::string ScopedKeyValuePair::to_html(Json &context) {
  std::vector<std::string> html_vector;
  std::transform(pairs.begin(), pairs.end(), html_vector.begin(),
                 [&](NodePtr p) -> std::string { return to_html(context); });
  return boost::algorithm::join(html_vector, "\n");
}
