/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8queens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinpark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:18:18 by jinpark           #+#    #+#             */
/*   Updated: 2019/03/09 13:45:15 by jinpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#define N 8

void printSolution(int map[N][N])
{
	int i, j;
	
	for (i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf(" %d ", map[i][j]);
		printf("\n");
	}
}

bool isSafe (int map[N][N], int row, int col)
{
	int i, j;

	for (i=0;i<col;i++)
		if (map[row][i])
			return (false);
	for (i=row,j=col;i>=0 && j>=0;i--,j--)
		if (map[i][j])
			return (false);
	for (i=row, j=col; j>=0 && i<N; i++,j--)
		if (map[i][j])
			return (false);
	return (true);
}

bool solveNQUtil (int map[N][N], int col)
{
	int i;
	if (col >= N)
		return (true);
	for (i=0; i<N; i++)
	{
		if (isSafe(map, i, col))
		{
			map[i][col] = 1;
			if (solveNQUtil(map, col+1))
				return (true);
			map[i][col] = 0;
		}
	}
	return (false);
}

bool solveNQ()
{
	int map[N][N] = {{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	if (solveNQUtil(map, 0) == false)
	{
		printf("solution doesn't exist");
		return (false);
	}
	printSolution(map);
	return (true);
}

int main(void)
{
	solveNQ();
	return 0;
}
