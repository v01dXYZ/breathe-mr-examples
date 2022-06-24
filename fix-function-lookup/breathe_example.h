#include <type_traits>
#include <vector>

constexpr int default_value() { return 0; }

/// could not be parsed by breathe
template <int i=default_value()> int f(int x);

/// With Transform
template <class Transform, typename T=int> auto g(std::vector<T>& vec) -> decltype(Transform::op(T{}));

/// Default
template<typename T=int> T g(std::vector<T>& vec);

class Transform {
public:
  static float op(int x);
};

void test() {
  std::vector<int> vec_int = {5, 3};
  g<Transform>(vec_int);
  g(vec_int);
}
