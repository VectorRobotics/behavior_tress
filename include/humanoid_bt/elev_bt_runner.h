#pragma once

#include <string>

namespace humanoid_bt
{
class ElevBTRunner
{
public:
  ElevBTRunner(const std::string& tree_file);

  void run();

private:
  std::string tree_file_;
};
} // namespace humanoid_bt
