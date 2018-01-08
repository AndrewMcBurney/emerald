#ifndef VALUELIST_H
#define VALUELIST_H

#include "node.hpp"

class ValueList : public Node {

public:
  ValueList(std::string keyword, NodePtrs literals);

  std::string check_keyword(NodePtr element, Json &context);
  std::string to_html(Json &context) override;

private:
  std::string keyword;
  NodePtrs literals;

};

#endif // VALUELIST_H
