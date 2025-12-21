
%: %.c
	gcc -g $< -o $@.out

	./$@.out
