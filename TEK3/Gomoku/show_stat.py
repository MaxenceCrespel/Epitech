import pstats

# Create a Stats object based on the file
p = pstats.Stats("./piskvork_linux/gomoku.prof")

# Sort the statistics by the cumulative time spent in the function
p.sort_stats("cumulative").print_stats(100)  # Print stats for the top 10 functions

# Other options for sorting and viewing the data include:
# p.sort_stats('time').print_stats(10)  # Sort by total time in the function
# p.sort_stats('calls').print_stats(10)  # Sort by the number of call
