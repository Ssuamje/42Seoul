/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:20:31 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 17:39:02 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	setStringUpper(char *string) {
	int i = 0;

	while (string[i] != '\0') {
		string[i] = std::toupper(string[i]);
		i++;
	}
}

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < ac; i++) {
			setStringUpper(av[i]);
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
	return 0;
}