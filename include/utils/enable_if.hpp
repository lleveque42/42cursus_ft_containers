/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:15:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/06 12:23:21 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft {

	template<bool Cond, class T = void>
		struct enable_if {};

	template<class T>
		struct enable_if<true, T> {
			typedef T type;
		};
}

#endif
