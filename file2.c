
extern int secretKey;

void tryToAccess() { int k = secretKey; }

void circleArea(int radius) {
  const float PI = 3.14159;

  // Valid
  float area = PI * radius * radius;

  // ERROR: Compiler will stop you here
  PI = 3.14;
}
