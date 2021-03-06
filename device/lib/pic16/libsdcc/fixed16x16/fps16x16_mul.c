
union u_t {
  long value;
  __fixed16x16 fix;
};

__fixed16x16 __fps16x16_mul(__fixed16x16 a, __fixed16x16 b)
{
  volatile union u_t u1, u2;

  u1.fix = a;
  u2.fix = b;
  
  u1.value = (u1.value >> 4) * (u2.value >> 4) >> 8;
  
  return (u1.fix);
}
