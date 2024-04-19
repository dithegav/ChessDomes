
CFLAGS = -Wall -g -std=c99 -static-libasan
CFLAGS_ASAN = -Wall -g -std=c99 -fsanitize=address -static-libasan

all: no_asan asan

no_asan: list1 chess tree1 tree2

tree1: lifo.o tree.o fifo.o list.o tree1.c 
	gcc $(CFLAGS) tree1.c list.o tree.o lifo.o fifo.o -o tree1

tree2: lifo.o tree.o fifo.o list.o tree2.c 
	gcc $(CFLAGS) tree2.c list.o tree.o lifo.o fifo.o -o tree2

list1: list1.c list.o
	gcc $(CFLAGS) list1.c list.o -o list1
	
chess: chess.c
	gcc $(CFLAGS) $< -o $@

%.o: %.h %.c
	gcc  $(CFLAGS) $*.c -c -o $*.o
	
asan: list1_asan chess_asan tree1_asan tree2_asan

tree1_asan: lifo.o_asan tree.o_asan fifo.o_asan list.o_asan tree1.c 
	gcc $(CFLAGS_ASAN) tree1.c list.o_asan tree.o_asan lifo.o_asan fifo.o_asan -o tree1_asan

tree2_asan: lifo.o_asan tree.o_asan fifo.o_asan list.o_asan tree2.c 
	gcc $(CFLAGS_ASAN) tree2.c list.o_asan tree.o_asan lifo.o_asan fifo.o_asan -o tree2_asan

list1_asan: list1.c list.o_asan
	gcc $(CFLAGS_ASAN) list1.c list.o_asan -o list1_asan
	
chess_asan: chess.c
	gcc $(CFLAGS_ASAN) $< -o $@

%.o_asan: %.h %.c
	gcc  $(CFLAGS_ASAN) $*.c -c -o $*.o_asan
	
clean:
	-[ ! -d "./out" ] && mkdir out
	-rm out/* *.o tree1 tree2 list1 chess *_asan
	
	
run: all
	xargs -a tests/a_210.arg ./list1 < tests/a_15.in > out/a_15.out
	-diff -urN tests/a_15.std out/a_15.out
	xargs -a tests/a_210.arg ./list1 < tests/a_16.in > out/a_16.out
	-diff -urN tests/a_16.std out/a_16.out
	xargs -a tests/a_210.arg ./list1 < tests/a_17.in > out/a_17.out
	-diff -urN tests/a_17.std out/a_17.out
	xargs -a tests/a_22680.arg ./list1 < tests/a_60.in > out/a_60_22680.out
	-diff -urN tests/a_60_22680.std out/a_60_22680.out
	xargs -a tests/a_22680.arg ./list1 < tests/a_67.in > out/a_67_22680.out
	-diff -urN tests/a_67_22680.std out/a_67_22680.out
	./tree1 < tests/post_order_14.in > tests/level_order_14.out
	-diff -urN tests/level_order_14.std tests/level_order_14.out
	./tree1 < tests/post_order_35.in > tests/level_order_35.out
	-diff -urN tests/level_order_35.std tests/level_order_35.out
	./tree2 < tests/tree2_a.in > tests/tree2_a.out
	-diff -urN tests/tree2_a.std tests/tree2_a.out
