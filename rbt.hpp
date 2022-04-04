/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:03 by csejault          #+#    #+#             */
/*   Updated: 2022/04/04 12:11:47 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//SOURCES :	Introduction to Algorithms : Thomas H. Cormen - Charles E. Leiserson - Ronald L. Rivest - Clifford Stein
//Class_Name = rbt

//define{
#ifndef RBT_HPP
# define RBT_HPP

# ifndef COL_GREEN
#  define COL_GREEN 		"\033[0;32m"
# endif
# ifndef COL_RED
#  define COL_RED		"\033[0;31m"
# endif
# ifndef COL_YELLOW
#  define COL_YELLOW		"\033[0;33m"
# endif
# ifndef COL_NORMAL
#  define COL_NORMAL		"\033[0m"
# endif

# include <iostream>
# include <memory>
# include "node.hpp"
template < class T >
class node;
//define - END}

template < class T, class Allocator = std::allocator<typename node<T>::node_type>>
class	rbt {
	public:
		enum	t_color {
			BLACK = 0,
			RED
		};
		typedef Allocator	allocator_type;
		typedef	typename node<T>::node_type		node_type;
		typedef	typename node<T>::nd			nd;
		typedef	typename node<T>::value_type	value_type;
		//pub_constructor{
		rbt(const allocator_type& alloc_arg = allocator_type()) : _alloc(alloc_arg)  {
			t_null = create_node(node_type(0));
			root = t_null;
		}
		~rbt( void ) { 
			delete_tree(root);
			delete_node(t_null);
		}

		//pub_constructor - END}

		//pub_operator{
		//pub_operator - END}

		//pub_debug{
		//pub_debug - END}

		//pub_static{

		//pub_static - END}

		//pub_getter{
		//pub_getter - END}

		//pub_setter{
		//pub_setter - END}

		//pub_exception{
		class	rotate_on_t_null : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Rotate on t_null");
		}
	};
		//pub_exception - END}

		//pub_fct{
		void	delete_node(nd to_dell)
		{
			_alloc.destroy(to_dell);
			_alloc.deallocate(to_dell, 1);
		}

		nd	create_node(node_type	value)
		{
			nd	ret;
			ret = _alloc.allocate(1);
			_alloc.construct(ret, value);
			return (ret);
		}

		void	add_node(value_type k)
		{
			nd n = create_node(node_type(&t_null,k));
			t_insert(n);
		}

		void	delete_tree( nd p )
		{
			if (p != t_null)
			{
				delete_tree(p->left);
				delete_tree(p->right);
				delete_node(p);
			}
		}

		void	inorder_walk( void )
		{
			inorder_walk(root);
		}

		void	inorder_walk( nd p )
		{
			if (p != t_null)
			{
				inorder_walk(p->left);
				p->print_key();
				inorder_walk(p->right);
			}
		}

		nd	search(value_type k)
		{
			return (search(root,k));
		}

		nd	search(nd n, value_type k)
		{
			if (n == t_null || n->key == k)
				return (n);
			if (k < n->key)
				return (search(n->left, k));
			else
				return (search(n->right, k));
		}

		nd	iterative_search(value_type k)
		{
			return(iterative_search(root,k));
		}

		nd	iterative_search(nd n, value_type k)
		{
			while (n != t_null && k != n->key)
			{
				if (k < n->key)
					n = n->left;
				else
					n = n->right;
			}
			return (n);
		}

		void	left_rotate(nd x)
		{
			if (x->right == t_null)
				throw (rotate_on_t_null());
			nd y = x->right;
			x->right = y->left;
			if (y->left != t_null)
				y->left->p = x;
			y->p = x->p;	
			if (x->p == t_null)
				root = y;
			else if (x == x->p->left)
				x->p->left = y;
			else
				x->p->right = y;
			y->left = x;
			x->p = y;
		}

		void	right_rotate(nd y)
		{
			if (y->left == t_null)
				throw (rotate_on_t_null());
			nd x = y->left;
			y->left = x->right;
			if (x->right != t_null)
				x->right->p = y;
			x->p = y->p;	
			if (y->p == t_null)
				root = x;
			else if (y == y->p->left)
				y->p->left = x;
			else
				y->p->right = x;
			x->right = y;
			y->p = x;
		}


		void	t_insert(nd z)
		{
			nd y = t_null;
			nd x = root;
			while (x != t_null)
			{
				y = x;
				if (z->key < x->key)
					x = x->left;
				else
					x = x->right;
			}
			z->p = y;
			if (y == t_null)
				root = z;
			else if (z->key < y->key)
				y->left = z;
			else
				y->right = z;
			t_insert_fixup(z);
		}

		void	t_insert_fixup(nd z)
		{
			nd uncle = t_null;
			//z is red at the begining
			while (z->p->color == RED)
			{
				// if z'parent is a left child
				if (z->p == z->p->p->left)
				{
					uncle = z->p->p->right;
					if (uncle->color == RED)
					{
						//case 1 - z's uncle is red
						z->p->color = BLACK;
						uncle->color = BLACK;
						z->p->p->color = RED;
						//jump to grand parent(which just turned red)
						z = z->p->p;
					}
					else 
					{
						//z is not the root because it has an uncle
						if (z == z->p->right)
						{
							//case 2 - z is right child and uncle black
							z = z->p;
							left_rotate(z);
						}
						//case 3 - 
						//right rotate if uncle is black (balance)
						z->p->color = BLACK;
						z->p->p->color = RED;
						right_rotate(z->p->p);
					}
				}
				else
				{
					// if z'parent is a right child
					uncle = z->p->p->left;
					if (uncle->color == RED)
					{
						//case 1 - z's uncle is red
						z->p->color = BLACK;
						uncle->color = BLACK;
						z->p->p->color = RED;
						//jump to grand parent(which just turned red)
						z = z->p->p;
					}
					else 
					{
						//z is not the root because it has an uncle
						if (z == z->p->left)
						{
							//case 2 - z is right child and uncle black
							z = z->p;
							right_rotate(z);
						}
						//case 3 - 
						//right rotate if uncle is black (balance)
						z->p->color = BLACK;
						z->p->p->color = RED;
						left_rotate(z->p->p);
					}
				}
			}
			root->color = BLACK;
		}

		void transplant(nd u, nd v)
		{
			if (u->p == t_null)
				root = v;
			else if (u == u->p->left)
				u->p->left = v;
			else
				u->p->right = v;
			v->p = u->p;
		}

		void	t_delete(nd z)
		{
			nd y = z;
			nd x = NULL;
			bool y_original_color = y->color;
			if (z->left == t_null)
			{
				x = z->right;
				transplant(z,z->right);
			}
			else if (z->right == t_null)
			{
				x = z->left;
				transplant(z,z->left);
			}
			else
			{
				y = z->right->minimum();
				y_original_color = y->color;
				if (y->p == z)
					x->p = y;
				else
				{
					transplant(y,y->right);
					y->right = z->right;
					y->right->p = y;
				}
				transplant(z,y);
				y->left = z->left;
				y->left->p = y;
				y->color = z->color;
				if (y_original_color == BLACK)
					t_delete_fixup(x);
			}
			//?
			delete_node(z);
		}

		void	t_delete_fixup(nd x)
		{
			nd w = NULL;
			while (x != root && x->color == BLACK)
			{
				if (x == x->p->left)
				{
					w = x->p->right;
					if (w->color == BLACK)
					{
						w->color = BLACK;
						x->p->color = RED;
						left_rotate(x->p);
						w = x->p->right;
					}
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						x = x->p;
					}
					else
					{
						if (w->right->color == BLACK)
						{
							w->left->color = BLACK;
							w->color = RED;
							right_rotate(w);
							w = x->p->right;
						}
						w->color = x->p->color;
						x->p->color = BLACK;
						w->right->color = BLACK;
						left_rotate(x->p);
						x = root;
					}
				}
				else
				{
					w = x->p->left;
					if (w->color == BLACK)
					{
						w->color = BLACK;
						x->p->color = RED;
						right_rotate(x->p);
						w = x->p->left;
					}
					if (w->right->color == BLACK && w->left->color == BLACK)
					{
						w->color = RED;
						x = x->p;
					}
					else
					{
						if (w->left->color == BLACK)
						{
							w->right->color = BLACK;
							w->color = RED;
							left_rotate(w);
							w = x->p->left;
						}
						w->color = x->p->color;
						x->p->color = BLACK;
						w->left->color = BLACK;
						right_rotate(x->p);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}

		//pub_fct - END}

		//pub_var{
		//pub_var - END}

	private:
		//priv_debug{
		//priv_debug - END}

		//priv_constructor{
		//priv_constructor - END}

		//priv_static{
		//priv_static - END}

		//priv_var{
		allocator_type	_alloc;
		nd				t_null;
		nd				root;
		//priv_var - END}
};

//out_class{
//std::ostream &	operator<<(std::ostream &os, rbt &to_print);
//out_class - END}

#endif

//Color{
//The codes for foreground and background colours are:
//
//         foreground background
//black        30         40
//red          31         41
//green        32         42
//yellow       33         43
//blue         34         44
//magenta      35         45
//cyan         36         46
//white        37         47
//Color - END}
