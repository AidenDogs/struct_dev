/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:48 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:49 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_ORDER_H
# define FOOD_ORDER_H

# include <stdlib.h>

struct OrderConfirmation;
struct OrderRequest;

int		process_food_order(struct OrderRequest *request);
int		check_restaurant_status(struct OrderRequest *request);
void 	send_confirmation_notification(struct OrderConfirmation *confirmation);
struct	OrderConfirmation *create_preorder_confirmation(void);
struct	OrderConfirmation *create_standard_confirmation(void);

#endif