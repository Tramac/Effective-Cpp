// -----Demo 1.保证类型正确-----
struct Day {
explicit Day(int d) : val(d)
{}
int val;
};

// struct Month {
// explicit Month(int m) : val(m)
// {}
// int val;
// };

// 定义所有有效的Months
class Month {
public:
  static Month Jan() { return Month(1); }
  static Month Feb() { return Month(2); }
  static Month Mar() { return Month(3); }
  static Month apr() { return Month(4); }
  static Month May() { return Month(5); }
  static Month Jun() { return Month(6); }
  static Month Jul() { return Month(7); }
  static Month Aug() { return Month(8); }
  static Month Sep() { return Month(9); }
  static Month Oct() { return Month(10); }
  static Month Nov() { return Month(11); }
  static Month Dec() { return Month(12); }

  Month() {}

private:
  explicit Month(int m) : val(m) {};
  int val;
};

struct Year {
explicit Year(int y) : val(y)
{}
int val;
};

// class Date
// {
// public:
//   Date(const Month& m, const Day& d, const Year& y) :
//   month(m.val), day(d.val), year(y.val)
//   {}
// private:
//   int month, day, year;
// };

// -----Demo 2.保证范围有效-----
class Date2 {
public:
Date2(const Month& m, const Day& d, Year& y) : 
month(m), day(d.val), year(y.val)
{}

private:
  int day, year;
  Month month;
};

// -----Demo 3.-----
class Investment {
};
