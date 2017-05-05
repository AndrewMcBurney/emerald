#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <string>

/**
 * Singleton class for transforming Emerald code into intermediate
 * representation to be parsed by the PEG grammar
 */
class PreProcessor {

public:
  static PreProcessor& get_instance() {
    static PreProcessor instance;
    return instance;
  }

  PreProcessor(PreProcessor const&)            = delete; // Copy constructor
  PreProcessor& operator=(PreProcessor const&) = delete; // Copy assignment
  PreProcessor(PreProcessor&&)                 = delete; // Move constructor
  PreProcessor& operator=(PreProcessor&&)      = delete; // Move assignment

  std::vector<std::string> process(std::vector<std::string>);

protected:
  PreProcessor();

private:
  void check_new_indent(const int&);
  void open_tags(const int&);
  void close_tags(const int&);
  void close_literal(const int&);
  void close_entered_tags(const int&);
  std::string remove_indent_whitespace(std::string);
  void check_and_enter_literal(const std::string&);

  bool in_literal, templateless_literal, preserve_html_literal;
  int current_indent, unclosed_indents;
  std::string output;
};

#endif // PREPROCESSOR_H
