/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:03:05 by csejault          #+#    #+#             */
/*   Updated: 2022/04/13 14:10:35 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP
#include "node.hpp"

template < class T >
class	rbt_iterator
{
	public:
		typedef T 											value_type;
		typedef value_type * 								pointer;
		typedef value_type & 								reference;
		typedef const value_type *							const_pointer;
		typedef const value_type &							const_reference;
		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef std::ptrdiff_t								difference_type;
		typedef	typename node<value_type>::node_type					node_type;
		typedef	typename node<value_type>::node_pointer				node_pointer;
		//typedef	typename node<T>::node_reference			node_reference;
		//typedef	typename node<T>::const_node_pointer		const_node_pointer;
		//typedef	typename node<T>::const_node_reference		const_node_reference;
		typedef rbt_iterator<value_type>								iterator;
		typedef const rbt_iterator<value_type>								const_iterator;
		//typedef rbt_iterator<node_type>								iterator;
		//typedef const rbt_iterator<node_type>				const_iterator;

		rbt_iterator( node_pointer nd ) :_ptr(nd) {}
		rbt_iterator( const rbt_iterator &to_cpy ) : _ptr(to_cpy._ptr) {}
		rbt_iterator & operator=( const rbt_iterator& asign ) { if (&asign != this)_ptr = asign._ptr; return *this;}
		~rbt_iterator( void ) {}

		bool	operator==(const rbt_iterator & rhs)
		{
			return ((_ptr == rhs._ptr));
		}

		bool	operator!=(const rbt_iterator & rhs)
		{
			return ((_ptr != rhs._ptr));
		}

		pointer	operator->( void )
		{
			return (_ptr->operator->());
		}

		const_pointer	operator->( void ) const
		{
			return (_ptr->operator->());
		}

		reference	operator*( void )
		{
			return (_ptr->operator*());
		}

		const_reference	operator*( void ) const
		{
			return (_ptr->operator*());
		}

		rbt_iterator &	operator++(void)
		{
			_ptr = _ptr->successor();
			return (*this);
		}

		rbt_iterator	operator++(int)
		{
			rbt_iterator tmp(*this);
			_ptr = _ptr->successor();
			return (tmp);
		}

		rbt_iterator &	operator--(void)
		{
			_ptr = _ptr->predecessor();
			return (*this);
		}

		rbt_iterator	operator--(int)
		{
			rbt_iterator tmp(*this);
			_ptr = _ptr->predecessor();
			return (tmp);
		}

		bool	operator==(rbt_iterator const &rhs) const
		{
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(rbt_iterator const &rhs) const
		{
			return (_ptr != rhs._ptr);
		}

	private:
		node_pointer _ptr;
};

#endif
