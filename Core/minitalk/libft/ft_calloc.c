/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felayan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:20:00 by felayan           #+#    #+#             */
/*   Updated: 2024/09/09 01:22:21 by felayan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*loc;
	size_t	tots;

	tots = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (tots / size != nmemb)
		return (NULL);
	loc = malloc (tots);
	if (!loc)
		return (NULL);
	ft_bzero(loc, tots);
	return (loc);
}
/*
#include <stdio.h>
#include "libft.h"
#include <stdint.h>
int main() {
    size_t nmemb;
    size_t size;
    int *arr;
    size_t i;

    // Test case 1: Normal case
    nmemb = 10;
    size = sizeof(int);
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Test case 1 (Normal case):\n");
    for (i = 0; i < nmemb; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]); // Should print 0 for all elements
    }
    free(arr);

    // Test case 2: Zero elements
    nmemb = 0;
    size = sizeof(int);
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Memory allocation with zero elements failed as expected.\n");
    } else {
        printf("Unexpected result for zero elements test case.\n");
        free(arr);
    }

    // Test case 3: Zero size
    nmemb = 10;
    size = 0;
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Memory allocation with zero size failed as expected.\n");
    } else {
        printf("Unexpected result for zero size test case.\n");
        free(arr);
    }

    // Test case 4: Overflow case
    nmemb = SIZE_MAX; // Large number
    size = 2;
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Memory allocation failed due to overflow.\n");
    } else {
        printf("Unexpected result for overflow test case.\n");
        free(arr);
    }

    return 0;
}
*/
