#include "rbt.hpp"
#include "rbt_iterator.hpp"
#include <utility>

int main( void )
{

	typedef std::pair<int, std::string>	type;

	rbt<type>*	tree = new rbt<type>();
	tree->insert_node(std::make_pair(1,"un"));
	tree->insert_node(std::make_pair(4,"quatre"));
	tree->insert_node(std::make_pair(12, "douze"));
	tree->insert_node(std::make_pair(2, "deux"));
	tree->insert_node(std::make_pair(6, "six"));
	tree->insert_node(std::make_pair(10, "dix"));
	tree->insert_node(std::make_pair(14, "quatorze"));
	tree->insert_node(std::make_pair(3, "trois"));
	tree->insert_node(std::make_pair(5, "cinq"));
	tree->insert_node(std::make_pair(7, "sept"));
	tree->insert_node(std::make_pair(9, "neuf"));
	tree->insert_node(std::make_pair(11, "onze"));
	tree->insert_node(std::make_pair(13, "treize"));
	tree->insert_node(std::make_pair(15, "quinze"));
	tree->inorder_walk();
	std::cout << std::endl;
	//tree->inorder_walk();
	tree->delete_node(std::make_pair(15, "quinze"));
	tree->inorder_walk();
	//tree->inorder_walk();
	std::cout << std::endl;

	rbt<type>::node_pointer ptr = tree->minimum();
	for (rbt<type>::iterator it(ptr); it != tree->get_t_null(); it++)
	{
		std::cout << "it = " <<  it->first << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	tree->inorder_walk();
	delete tree;
	//rbt<int>*	tr = new rbt<int>();

	//rbt<int>*	tree = new rbt<int>();
	//tree->insert_node(8);
	//tree->insert_node(4);
	//tree->insert_node(12);
	//tree->insert_node(2);
	//tree->insert_node(6);
	//tree->insert_node(10);
	//tree->insert_node(14);
	//tree->insert_node(1);
	//tree->insert_node(3);
	//tree->insert_node(5);
	//tree->insert_node(7);
	//tree->insert_node(9);
	//tree->insert_node(11);
	//tree->insert_node(13);
	//tree->insert_node(15);
	//tree->inorder_walk();
	//std::cout << std::endl;
	////tree->inorder_walk();
	//tree->delete_node(15);
	//tree->inorder_walk();
	////tree->inorder_walk();
	//std::cout << std::endl;

	//rbt<int>::node_pointer ptr = tree->minimum();
	//for (rbt<int>::iterator it(ptr); it != tree->get_t_null(); it++)
	//{
	//	*it = *it *2;
	//	std::cout << "new it = " <<  *it << std::endl;
	//}
	//std::cout << std::endl;
	//std::cout << std::endl;
	//tree->inorder_walk();
	//delete tr;
	//delete tree;

	return (0);
}
