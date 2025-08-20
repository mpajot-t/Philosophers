/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpajot-t <mpajot-t@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:23:58 by mpajot-t          #+#    #+#             */
/*   Updated: 2025/08/20 10:23:58 by mpajot-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main(int argc, char **argv)
{
	if (argc < 4 || argc > 5)
		return (0);
	if (check_args(argv) == 0)
		printf("erreur");
	else
		printf("pas erreur");
	return (1);
}
