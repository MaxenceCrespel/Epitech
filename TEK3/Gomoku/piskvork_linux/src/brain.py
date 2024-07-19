from src.utils import pipeOut
from src.debug import Debug
from src.patterns import Patterns


class Brain:
    def __init__(self, debug=None):
        self.pattern_checker = Patterns(1, 2, 0, debug)
        self.board = None
        self.is_inited = False
        self.infos = {}
        self.debug: Debug = debug
        self.size_x = 0
        self.size_y = 0

        # directions 1 dist
        # self.directions = [
        #     (0, 1),
        #     (1, 0),
        #     (0, -1),
        #     (-1, 0),
        #     (1, 1),
        #     (-1, 1),
        #     (1, -1),
        #     (-1, -1),
        # ]

        # directions 3 star
        self.directions = [
            (0, 1),
            (1, 0),
            (0, -1),
            (-1, 0),
            (1, 1),
            (-1, 1),
            (1, -1),
            (-1, -1),
            (2, 0),
            (0, 2),
            (-2, 0),
            (0, -2),
            (2, 2),
            (2, -2),
            (-2, -2),
            (-2, 2),
            # (3, 0),
            # (0, 3),
            # (-3, 0),
            # (0, -3),
            # (3, 3),
            # (3, -3),
            # (-3, -3),
            # (-3, 3),
            # (4, 0),
            # (0, 4),
            # (-4, 0),
            # (0, -4),
            # (4, 4),
            # (4, -4),
            # (-4, -4),
            # (-4, 4),
        ]

        # directions 2 dist
        # self.directions = [
        #     (0, 1),
        #     (1, 0),
        #     (0, -1),
        #     (-1, 0),
        #     (1, 1),
        #     (-1, 1),
        #     (1, -1),
        #     (-1, -1),
        #     (2, 0),
        #     (0, 2),
        #     (-2, 0),
        #     (0, -2),
        #     (1, 2),
        #     (1, -2),
        #     (-1, -2),
        #     (-1, 2),
        #     (2, 1),
        #     (2, -1),
        #     (-2, -1),
        #     (-2, 1),
        #     (2, 2),
        #     (2, -2),
        #     (-2, -2),
        #     (-2, 2),
        # ]

    def is_free(self, x, y):
        return self.board[y][x] == 0

    def get_board(self):
        return self.board

    def init_brain(self, size_x: int, size_y: int):
        self.is_inited = True
        self.size_x = size_x
        self.size_y = size_y
        self.board = [[0 for _ in range(size_x)] for _ in range(size_y)]
        pipeOut("OK")

    def is_valid(self, x, y):
        if not self.is_free(x, y):
            pipeOut(f"ERROR {x},{y} not free")
            return False
        return True

    def opponent_turn(self, x, y):
        if self.is_valid(x, y):
            self.board[y][x] = 2

    def my_turn(self, x, y):
        if self.is_valid(x, y):
            self.board[y][x] = 1
            pipeOut(f"{x},{y}")

    def block(self, x, y):
        if self.is_valid(x, y):
            self.board[y][x] = 3

    def take_back(self, x, y):
        self.board[y][x] = 0

    def mock_my_turn(self, x, y):
        self.board[y][x] = 1

    def mock_opponent_turn(self, x, y):
        self.board[y][x] = 2

    def restore(self, x, y):
        self.board[y][x] = 0

    def repr_board(self, board=None):
        if not board:
            board = self.board
        string = "\n".join([" ".join([str(x) for x in row]) for row in board])
        string = string.replace("0", ".")
        string = string.replace("1", "O")
        string = string.replace("2", "X")
        string = string.replace("3", "#")
        return string

    def find_adjacent_coordinates(self):
        adj_coords = []
        for y in range(self.size_y):
            for x in range(self.size_x):
                if self.board[y][x] == 1 or self.board[y][x] == 2 or self.board[y][x] == 3:
                    for dir_x, dir_y in self.directions:
                        if (
                            0 <= x + dir_x < self.size_x
                            and 0 <= y + dir_y < self.size_y
                            and self.board[y + dir_y][x + dir_x] == 0
                        ):
                            adj_coords.append((x + dir_x, y + dir_y))
        coords = list(set(adj_coords))
        return coords

    def count_aligned_pawns(self, x, y, player):
        MAX = 6

        def is_valid(i, j):
            return 0 <= i < self.size_y and 0 <= j < self.size_x

        def check_direction(dx, dy):
            count, open_ends = 0, 1

            if self.board[y][x] == 0:
                open_ends = 1

            i, j = x + dx, y + dy
            c = 0
            while is_valid(i, j) and self.board[j][i] == player and c < MAX:
                i, j = i + dx, j + dy
                count += 1
                c += 1
            if is_valid(i, j) and self.board[j][i] == 0:
                open_ends += 1

            i, j = x - dx, y - dy
            c = 0
            while is_valid(i, j) and self.board[j][i] == player and c < MAX:
                i, j = i - dx, j - dy
                count += 1
                c += 1
            if is_valid(i, j) and self.board[j][i] == 0:
                open_ends += 1

            return count, open_ends

        directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        max_count, total_open_ends = 0, 0

        for dx, dy in directions:
            count, open_ends = check_direction(dx, dy)
            if count > max_count or (count == max_count and open_ends > total_open_ends):
                max_count, total_open_ends = count, open_ends

        return max_count, total_open_ends

    def evaluate_position(self, x, y):
        score = 0
        for player, mult in [(1, 1), (2, -1.1)]:
            # for dir_x, dir_y in [(0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (-1, 1), (1, -1), (-1, -1)]:
            aligned, open_end = self.count_aligned_pawns(x, y, player)
            if aligned >= 5 or (aligned >= 4 and open_end > 1):
                return float("inf") * mult
            elif aligned >= 4 and open_end > 0:
                score += 50000 * mult
            elif aligned == 3 and open_end > 1:
                score += 100000 * mult
            else:
                score += (aligned**2 * (open_end + 1)) * mult

            for pattern, value in self.pattern_checker.patterns:
                score += pattern(x, y, self.board, player) * value * mult
        return score

    def is_finished(self):
        for y in range(self.size_y):
            for x in range(self.size_x):
                if self.board[y][x] != 0:
                    player = self.board[y][x]
                    count, open_end = self.count_aligned_pawns(x, y, player)
                    if count >= 5 or (count >= 4 and open_end >= 1):
                        return True
        return False

    def minmax_alpha_beta(self, depth, alpha, beta, maximizing_player, move):
        if depth == 0 or self.is_finished():
            return self.evaluate_position(*move)

        adjacent_coords = self.find_adjacent_coordinates()
        if maximizing_player:
            max_eval = float("-inf")
            for x, y in adjacent_coords:
                if self.board[y][x] == 0:
                    self.mock_my_turn(x, y)
                    eval = self.minmax_alpha_beta(depth - 1, alpha, beta, False, move)
                    self.restore(x, y)
                    max_eval = max(max_eval, eval)
                    alpha = max(alpha, max_eval)
                    if beta <= alpha:
                        break
            return max_eval
        else:
            min_eval = float("inf")
            for x, y in adjacent_coords:
                if self.board[y][x] == 0:
                    self.mock_opponent_turn(x, y)
                    eval = self.minmax_alpha_beta(depth - 1, alpha, beta, True, move)
                    self.restore(x, y)
                    min_eval = min(min_eval, eval)
                    beta = min(beta, min_eval)
                    if beta <= alpha:
                        break
            return min_eval

    def turn(self):
        best_score = float("-inf")
        best_move = None

        adj_coords = self.find_adjacent_coordinates()
        for x, y in adj_coords:
            self.board[y][x] = 3
        self.debug.log(self.repr_board())
        for x, y in adj_coords:
            self.board[y][x] = 0
        for x, y in adj_coords:
            if self.board[y][x] == 0:
                self.mock_my_turn(x, y)
                score = self.minmax_alpha_beta(2, float("-inf"), float("inf"), False, (x, y))
                self.restore(x, y)
                if score > best_score:
                    best_score = score
                    best_move = (x, y)

        if best_move:
            self.my_turn(best_move[0], best_move[1])
        elif len(adj_coords) == 0:
            self.my_turn(10, 10)
        else:
            self.my_turn(adj_coords[0][0], adj_coords[0][1])

    def end(self):
        exit(0)

    def about(self):
        pass

    def info(self, key, value):
        if key in ["timeout_turn", "timeout_match", "max_memory", "time_left"]:
            try:
                self.infos[key] = int(value)
            except ValueError:
                self.pipeOut("ERROR")
        else:
            self.infos[key] = value
