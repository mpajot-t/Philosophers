/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:58 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/21 11:23:14 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (check_args(argv) == 0)
		return (0);
	else
		printf("hey");
	return (0);
}
