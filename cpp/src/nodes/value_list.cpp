#include "value_list.hpp"

ValueList::ValueList(std::string keyword, NodePtrs literals) : keyword(keyword), literals(literals) {}

std::string ValueList::check_keyword(NodePtr element, Json &context) {
  if (keyword == "images")
    return "<img src=\"" + element->to_html(context) + "\"/>";
  else if (keyword == "styles")
    return "<link rel=\"stylesheet\" href=\"" + element->to_html(context) + "\"/>";
  else if (keyword == "scripts")
    return "<script type=\"text/javascript\" src=\"" + element->to_html(context) + "\"/>";
  else
    return "";
}

std::string ValueList::to_html(Json &context) {
  std::vector<std::string> html_vector;
  std::transform(literals.begin(), literals.end(), html_vector.begin(),
                 [&](NodePtr p) -> std::string { return check_keyword(p, context); });

  return boost::algorithm::join(html_vector, "\n");
}
