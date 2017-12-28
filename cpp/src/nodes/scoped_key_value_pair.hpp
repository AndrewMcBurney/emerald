#ifndef SCOPEDKEYVALUEPAIR_H
#define SCOPEDKEYVALUEPAIR_H

#include "node.hpp"

/**
 * Scoped key value pairs, scoped to a particular base_keyword in 'pair_list' rule
 *
 * Scoped to pair_list (has knowledge of base_keyword, NOTE: not a parser rule in emerald_parser)
 */
class ScopedKeyValuePair : public Node {

public:
  ScopedKeyValuePair(NodePtrs);

  std::string to_html(Json &context) override;

private:
  NodePtrs pairs;

};

#endif // SCOPEDKEYVALUEPAIR_H
