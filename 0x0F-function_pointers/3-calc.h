#ifndef CALC_H
#define CALC_H
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
struct op
{
	char *op;
	int (*f)(int a, int b);
};

/**
 * op_t - typedef for struct op
 */
typedef struct op op_t;

#endif /* CALC_H */
