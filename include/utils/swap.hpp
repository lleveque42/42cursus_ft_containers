/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:23:46 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/13 22:27:44 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
# define SWAP_HPP

namespace ft {

	template<typename T>
	void swap(T &x, T &y) {
		T tmp = x;

		x = y;
		y = tmp;
	}
}

#endif
