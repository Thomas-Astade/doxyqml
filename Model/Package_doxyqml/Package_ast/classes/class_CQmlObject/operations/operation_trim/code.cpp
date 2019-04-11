//~~ const std::string trim(const std::string& s) [CQmlObject] ~~
std::string::size_type first = s.find_first_not_of(" \n\t\r");
if( first == std::string::npos) {
  return std::string();
}
else {
  std::string::size_type last = s.find_last_not_of(" \n\t\r"); /// must succeed
  return s.substr( first, last - first + 1);
}
