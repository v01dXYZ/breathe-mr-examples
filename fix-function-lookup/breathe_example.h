struct A {
  using IdType = int;

  IdType id;
};
/// A
template <typename T> auto get_id(T a) -> typename decltype(a)::IdType;
/// B
template <typename T> T get_id(T a);
