/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:17:54 by lleveque          #+#    #+#             */
/*   Updated: 2022/10/07 14:32:32 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL
# define IS_INTEGRAL

namespace ft {

	template<typename T, T v>
		struct integral_constant {
			static const T value = v;
			typedef T value_type;
			typedef integral_constant<T,v> type;
			operator T() { return v; }
		};

		typedef integral_constant<bool, true> true_type;
		typedef integral_constant<bool, false> false_type;

		template<typename T>
			struct is_integral : public false_type {};

		template<>
			struct is_integral<bool> : public true_type {};

		template<>
			struct is_integral<char> : public true_type {};

		template<>
			struct is_integral<signed char> : public true_type {};

		template<>
			struct is_integral<unsigned char> : public true_type {};

		template<>
			struct is_integral<wchar_t> : public true_type {};

		template<>
			struct is_integral<short> : public true_type {};

		template<>
			struct is_integral<unsigned short> : public true_type {};

		template<>
			struct is_integral<int> : public true_type {};

		template<>
			struct is_integral<unsigned int> : public true_type {};

		template<>
			struct is_integral<long> : public true_type {};

		template<>
			struct is_integral<unsigned long> : public true_type {};

		// template<> struct is_integral<long long>          { typedef true_type type; };
		// template<> struct is_integral<unsigned long long> { typedef true_type type; };
}

#endif
