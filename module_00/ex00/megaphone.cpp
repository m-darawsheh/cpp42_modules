/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarawsh <mdarawsh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:45:38 by mdarawsh          #+#    #+#             */
/*   Updated: 2025/07/09 17:49:01 by mdarawsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main(int argc, char	*argv[])
{
	if (argc < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		int i = 1;
		int j = 0;
		while (argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				std::cout << (char) toupper(argv[i][j]);
				j++;
			}
			i++;
		}
		std::cout << "\n";
	}
	return 0;
}
