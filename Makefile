
%: %.c
	gcc -g $< -o $@.out

	./$@.out

	@rm $@.out
