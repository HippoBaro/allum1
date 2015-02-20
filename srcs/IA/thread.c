/*
** thread.c for allum1 in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Wed Feb 18 21:35:58 2015 Hippolyte Barraud
** Last update Thu Feb 19 16:52:58 2015 Hippolyte Barraud
*/

#include "../../includes/alum1.h"

/*
** Starting from SLES 10, LinuxThreads is no longer supported.
** The new implementation of pthread on Linux, Native POSIX
** Thread Library (NPTL), does not have a limit on the number threads that
** can be created except for actual resource availability.
** Therefore, the PTHREAD_THREAD_MAX macro is no longer defined
** in the SLES 10 system header files.
*/
static void	schedule_threads(t_map *map, t_thread_query *query)
{
  int		i;

  i = 0;
  while (i < query->threadcount)
    {
      query->queries[i].from_heap = query->levelcount;
      query->queries[i].map = map;
      if (query->levelcount + THREAD_GRANULARITY <= map->levelcount)
	query->queries[i].to_heap = query->levelcount += THREAD_GRANULARITY;
      else
	query->queries[i].to_heap = query->levelcount + map->levelcount
	  - query->levelcount;
      if (pthread_create(&query->tids[i], NULL, &get_moves,
			 &query->queries[i]) != SUCCESS)
	print_error(ERROR_THREAD_CREATE, TRUE);
      map->total_thread++;
      i++;
    }
}

static t_moves	*await_threads(t_thread_query *query)
{
  int		i;

  i = 0;
  while (i < query->threadcount)
    {
      if (pthread_join(query->tids[i], &query->statuses[i]) != SUCCESS)
	print_error(ERROR_THREAD_JOIN, TRUE);
      i++;
    }
  return (merge_list((t_moves **)query->statuses, query->threadcount));
}

static void	free_thread_query(t_thread_query *query)
{
  free(query->queries);
  free(query->tids);
  free(query->statuses);
}

static t_moves		*bypass_threading(t_map *map)
{
  t_moves_query		query;

  query.to_heap = map->levelcount;
  query.from_heap = 0;
  query.map = map;
  return (get_moves(&query));
}

t_moves			*get_moves_threaded(t_map *map)
{
  t_thread_query	query;
  t_moves		*answer;

  map->gaus_pass++;
  if (ENABLE_THREADING == FALSE)
    return (bypass_threading(map));
  query.levelcount = 0;
  query.threadcount = (map->levelcount / THREAD_GRANULARITY);
  if (query.threadcount * THREAD_GRANULARITY < map->levelcount)
    query.threadcount++;
  map->concurrent_job = query.threadcount;
  query.queries = xmalloc(sizeof(t_moves_query) * query.threadcount);
  query.tids = xmalloc(sizeof(pthread_t) * query.threadcount);
  query.statuses = xmalloc(sizeof(void *) * query.threadcount);
  schedule_threads(map, &query);
  answer = await_threads(&query);
  free_thread_query(&query);
  return (answer);
}
