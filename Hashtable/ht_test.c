/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:57:07 by bammar            #+#    #+#             */
/*   Updated: 2022/12/24 15:27:01 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hashtable/ht.h"
#include <assert.h>
#include <string.h>

int	main(void)
{
	t_ht *table;

	// Test ht_new
	table = ht_new(10);
	assert(table != NULL);
	assert(table->total_size == 10);
	assert(table->array != NULL);
	assert(table->size == 0);

	// Test ht_set
	assert(ht_set(table, "key1", "value1") == 1);
	assert(ht_set(table, "key2", "value2") == 1);
	assert(ht_set(table, "key3", "value3") == 1);
	assert(table->size == 3);

	// // Test ht_get
	// assert(strcmp(ht_get(table, "key1"), "value1") == 0);
	// assert(strcmp(ht_get(table, "key2"), "value2") == 0);
	// assert(strcmp(ht_get(table, "key3"), "value3") == 0);
	// assert(ht_get(table, "non-existent-key") == NULL);

	// // Test ht_contains
	// assert(ht_contains(table, "key1") == 1);
	// assert(ht_contains(table, "key2") == 1);
	// assert(ht_contains(table, "key3") == 1);
	// assert(ht_contains(table, "non-existent-key") == 0);

	// Test ht_remove
    assert(table->size == 3);
    ht_remove(table, "key2");
    assert(table->size == 2);
    assert(ht_get(table, "key1") != NULL);
    assert(ht_get(table, "key2") == NULL);
    assert(ht_get(table, "key3") != NULL);
    ht_remove(table, "key1");
    ht_remove(table, "key3");
    assert(table->size == 0);

	// // Test ht_get
	assert(ht_get(table, "key1") == NULL);
	assert(ht_get(table, "key2") == NULL);
	assert(ht_get(table, "key3") == NULL);
	assert(ht_get(table, "non-existent-key") == NULL);


	// // Test ht_isempty
	// assert(ht_isempty(table) == 0);
	// ht_clear(table);
	assert(ht_isempty(table) == 1);


	// Test ht_set
	assert(ht_set(table, "key1", "value1") == 1);
	assert(ht_set(table, "key2", "value2") == 1);
	assert(ht_set(table, "key3", "value3") == 1);
	assert(table->size == 3);
	
	// Test ht_replace
	assert(strcmp(ht_get(table, "key1"), "value1") == 0);
	ht_replace(table, "key1", "new-value1");
	assert(strcmp(ht_get(table, "key1"), "new-value1") == 0);
	assert(table->size == 3);

	// Test ht_clear
	assert(table->size == 3);
	ht_clear(table);
	assert(table->size == 0);
	assert(ht_get(table, "key1") == NULL);
	assert(ht_get(table, "key2") == NULL);
	assert(ht_get(table, "key3") == NULL);

	assert(ht_set(table, "key1", "value1") == 1);
	assert(ht_set(table, "key2", "value2") == 1);
	assert(ht_set(table, "key3", "value3") == 1);
	assert(table->size == 3);
		
	assert(ht_get(table, "key1") != NULL);
	assert(ht_get(table, "key2") != NULL);
	assert(ht_get(table, "key3") != NULL);

	ht_destroy(table);

	return (0);
}