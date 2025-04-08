#ifndef FIXED_POINT_H
#define FIXED_POINT_H

typedef int fixed_point;

#define F (1 << 14)  // 2^14, 고정소수점 비트 위치

/* 정수 <-> 고정소수점 변환 */
#define INT_TO_FP(n) ((n) * F)
#define FP_TO_INT_ZERO(x) ((x) / F)  // 소수점 버림
#define FP_TO_INT_NEAR(x) ((x) >= 0 ? ((x) + F / 2) / F : ((x) - F / 2) / F)  // 반올림

/* 고정소수점끼리 연산 */
#define ADD_FP(x, y) ((x) + (y))
#define SUB_FP(x, y) ((x) - (y))
#define MUL_FP(x, y) (((int64_t)(x)) * (y) / F)
#define DIV_FP(x, y) (((int64_t)(x)) * F / (y))

/* 고정소수점과 정수 간 연산 */
#define ADD_MIX(x, n) ((x) + (n) * F)
#define SUB_MIX(x, n) ((x) - (n) * F)
#define MUL_MIX(x, n) ((x) * (n))
#define DIV_MIX(x, n) ((x) / (n))

#endif /* FIXED_POINT_H */
