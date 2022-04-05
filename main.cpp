#include "rbt.hpp"
#include "rbt_iterator.hpp"

int main( void )
{
	rbt<int>*	tr = new rbt<int>();

	rbt<int>*	tree = new rbt<int>();
	tree->add_node(8);
	tree->add_node(4);
	tree->add_node(12);
	tree->add_node(2);
	tree->add_node(6);
	tree->add_node(10);
	tree->add_node(14);
	tree->add_node(1);
	tree->add_node(3);
	tree->add_node(5);
	tree->add_node(7);
	tree->add_node(9);
	tree->add_node(11);
	tree->add_node(13);
	tree->add_node(15);
	tree->inorder_walk();
	std::cout << std::endl;
	//tree->inorder_walk();
	tree->t_delete(tree->search(15));
	tree->inorder_walk();
	//tree->inorder_walk();
	std::cout << std::endl;

	rbt<int>::node_pointer ptr = tree->search(1);
	for (rbt<int>::iterator it(ptr); it != tree->search(15); it++)
	{
		*it = *it *2;
		std::cout << "new it = " <<  *it << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	tree->inorder_walk();
	delete tr;
	delete tree;
	return (0);
}
