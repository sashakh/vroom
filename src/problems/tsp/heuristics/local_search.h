#ifndef TSP_LOCAL_SEARCH_H
#define TSP_LOCAL_SEARCH_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <list>
#include <vector>

#include "structures/abstract/matrix.h"
#include "structures/typedefs.h"

class tsp_local_search {
private:
  const matrix<cost_t>& _matrix;
  const std::pair<bool, index_t> _avoid_start_relocate;
  std::vector<index_t> _edges;
  unsigned _nb_threads;
  std::vector<index_t> _rank_limits;
  std::vector<index_t> _sym_two_opt_rank_limits;

public:
  tsp_local_search(const matrix<cost_t>& matrix,
                   std::pair<bool, index_t> avoid_start_relocate,
                   const std::list<index_t>& tour,
                   unsigned nb_threads);

  cost_t relocate_step();

  cost_t perform_all_relocate_steps();

  cost_t avoid_loop_step();

  cost_t perform_all_avoid_loop_steps();

  cost_t two_opt_step();

  cost_t asym_two_opt_step();

  cost_t perform_all_two_opt_steps();

  cost_t perform_all_asym_two_opt_steps();

  cost_t or_opt_step();

  cost_t perform_all_or_opt_steps();

  std::list<index_t> get_tour(index_t first_index) const;
};

#endif
