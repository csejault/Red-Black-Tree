#include "rbt.hpp"

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
	delete tr;
	delete tree;
	return (0);
}
