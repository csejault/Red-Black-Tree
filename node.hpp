/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:50:03 by csejault          #+#    #+#             */
/*   Updated: 2022/04/04 11:52:58 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//SOURCES :	Introduction to Algorithms : Thomas H. Cormen - Charles E. Leiserson - Ronald L. Rivest - Clifford Stein
//Class_Name = node

//define{
#ifndef NODE_HPP
# define NODE_HPP

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
//define - END}

template < class T >
class	node {

	public:
		enum	t_color {
			BLACK = 0,
			RED
		};
		typedef node<T> 	node_type;
		typedef node_type* 	nd;
		typedef T			value_type;
		typedef T*			pointer;
		typedef T&			reference;

		//pub_constructor{
		node(value_type k) : color(BLACK), p(NULL), left(NULL), right(NULL), key(k) {} //used to create t_null
		node(nd* t_null, value_type k) : color(RED), p(*t_null), left(*t_null), right(*t_null), key(k) {} //used to create node
		~node( void ) {
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
		//pub_exception - END}

		//pub_fct{
		void	print_key( void ) {
			std::cout << key << std::endl;
		}
		nd	minimum( void )
		{
			nd m = this;
			while (m->left)
				m = m->left;
			return (m);
		}

		nd	maximum( void )
		{
			nd m = this;

			while (m->right)
				m = m->right;
			return (m);
		}

		nd predecessor(nd n)
		{
			nd s = NULL;
			if (n->left)
				return (n->left->minimum());
			s = n->p;
			while(s && n == s->left)
			{
				n = s;
				s = s->p;
			}
			return (s);
		}

		nd successor(nd n)
		{
			nd s = NULL;
			if (n->right)
				return (n->right->minimum());
			s = n->p;
			while(s && n == s->right)
			{
				n = s;
				s = s->p;
			}
			return (s);
		}
		//pub_fct - END}

		//pub_var{
		bool	color;
		nd		p;
		nd		left;
		nd		right;
		value_type	key;
		//pub_var - END}

	private:
		//priv_debug{
		//priv_debug - END}

		//priv_constructor{
		node( void ) {};
		//priv_constructor - END}

		//priv_static{
		//priv_static - END}

		//priv_var{
		//priv_var - END}
};

//out_class{
//std::ostream &	operator<<(std::ostream &os, node &to_print);
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
