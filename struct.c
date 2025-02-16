// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   struct.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/02/16 14:15:07 by ahakki            #+#    #+#             */
// /*   Updated: 2025/02/16 14:55:17 by ahakki           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "minishell.h"

// // Add child to the left side of the current node
// void	add_child_left(t_node **node, char *child)
// {
// 	if (!node || !child)
// 		return ;
// 	// Allocate memory for child node if it doesn't exist
// 	if (!(*node)->child)
// 		(*node)->child = (t_node *)malloc(sizeof(t_node));
// 	if (!(*node)->child)
// 		return ; // Ensure memory allocation succeeded
// 	(*node)->child->left = child;
// 	(*node)->child->child = NULL;
// }

// // Add child to the right side of the current node
// void	add_child_right(t_node **node, char *child)
// {
// 	if (!node || !child)
// 		return ;
// 	// Allocate memory for child node if it doesn't exist
// 	if (!(*node)->child)
// 		(*node)->child = (t_node *)malloc(sizeof(t_node));
// 	if (!(*node)->child)
// 		return ; // Ensure memory allocation succeeded
// 	(*node)->child->right = child;
// 	(*node)->child->child = NULL;
// }

// // Create a new node with left content
// t_node	*ft_lstnew_left(char *content)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->left = content;
// 	new_node->child = NULL;
// 	return (new_node);
// }

// // Create a new node with right content
// t_node	*ft_lstnew_right(char *content)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->right = content;
// 	new_node->child = NULL;
// 	return (new_node);
// }


