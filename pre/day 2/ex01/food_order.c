/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   food_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <apeero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:50:45 by apeero            #+#    #+#             */
/*   Updated: 2025/06/19 16:50:46 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	struct OrderConfirmation *confirmation;

	if (check_restaurant_status(request))
		confirmation = create_standard_confirmation();
	else
		confirmation = create_preorder_confirmation();

	if (confirmation == NULL)
		return (0);
	send_confirmation_notification(confirmation);
	return (1);
}
