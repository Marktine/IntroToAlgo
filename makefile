linked-list-test:
	gcc -o ./build/linked-list-test ./LinkedList/Implementation/list-node.c ./LinkedList/Implementation/linked-list.c ./LinkedList/Implementation/__tests__/test_linked_list.c
clean:
	@echo "Cleaning up executable files..."
	rm -rvf ./build/*