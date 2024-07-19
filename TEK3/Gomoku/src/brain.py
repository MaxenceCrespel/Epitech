from src.utils import pipeOut
from src.debug import Debug
from src.patterns import Patterns
from time import time


class Brain:
    def __init__(self, debug=None):
        self.pattern_checker = Patterns(1, 2, 0, debug)
        self.board = None
        self.is_inited = False
        self.infos = {}
        self.debug: Debug = debug
        self.size_x = 0
        self.size_y = 0
        self.played = []
        self.time = 0

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
            # (2, 0),
            # (0, 2),
            # (-2, 0),
            # (0, -2),
            # (2, 2),
            # (2, -2),
            # (-2, -2),
            # (-2, 2),
        ]

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
            self.mock_opponent_turn(x, y)

    def my_turn(self, x, y):
        if self.is_valid(x, y):
            self.mock_my_turn(x, y)
            pipeOut(f"{x},{y}")

    def block(self, x, y):
        if self.is_valid(x, y):
            self.board[y][x] = 3

    def take_back(self, x, y):
        self.board[y][x] = 0

    def mock_my_turn(self, x, y):
        self.board[y][x] = 1
        self.played.append((x, y))

    def mock_opponent_turn(self, x, y):
        self.board[y][x] = 2
        self.played.append((x, y))

    def restore(self, x, y):
        self.board[y][x] = 0
        self.played.pop()

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
        for x, y in self.played:
            if self.board[y][x] == 1 or self.board[y][x] == 2:
                for dir_x, dir_y in self.directions:
                    if (
                        0 <= x + dir_x < self.size_x
                        and 0 <= y + dir_y < self.size_y
                        and self.board[y + dir_y][x + dir_x] == 0
                    ):
                        adj_coords.append((x + dir_x, y + dir_y))
        return list(set(adj_coords))

    def count_aligned_pawns(self, x, y, player):
        MAX = 6

        def is_valid(i, j):
            return 0 <= i < self.size_x and 0 <= j < self.size_y

        def check_direction(dx, dy):
            count = 1
            open_ends = 0

            def count_in_direction(delta_x, delta_y):
                nonlocal count, open_ends
                i, j = x + delta_x, y + delta_y
                while is_valid(i, j) and self.board[j][i] == player and count < MAX:
                    count += 1
                    i, j = i + delta_x, j + delta_y
                if is_valid(i, j) and self.board[j][i] == 0:
                    open_ends += 1

            count_in_direction(dx, dy)
            count_in_direction(-dx, -dy)

            return count, open_ends

        directions = [(0, 1), (1, 0), (1, 1), (1, -1)]
        return [check_direction(dx, dy) for dx, dy in directions]

    def evaluate_position(self, x, y, depth):
        score = 0

        def get_pattern_score(pattern_length, open, is_my: bool):
            if pattern_length >= 5:
                return 600000000 * depth if is_my else 1000000
            if pattern_length >= 4 and open > 1:
                return 500000 if is_my else 1000000
            if pattern_length == 4 and open > 0:
                return 25200 if is_my else 40000
            if pattern_length == 3:
                if open > 1:
                    return 20000 if is_my else 50000
                if open > 0:
                    return 10000 if is_my else 19900
            if pattern_length == 2:
                if open > 1:
                    return 1000 if is_my else 3000
                if open > 0:
                    return 100 if is_my else 300
            if pattern_length == 1 and open > 1:
                return 10 if is_my else 30
            return pattern_length**2 * open + 1

        my_patterns = self.count_aligned_pawns(x, y, 1)
        their_patterns = self.count_aligned_pawns(x, y, 2)
        for pattern in my_patterns:
            score += get_pattern_score(*pattern, True)
        for pattern in their_patterns:
            score += get_pattern_score(*pattern, False)

        # for pattern, value in self.pattern_checker.patterns:
        #     score += pattern(x, y, self.board, 1) * value
        return score

    def is_finished(self):
        for x, y in self.played:
            if self.board[y][x] != 0:
                player = self.board[y][x]
                for count, _ in self.count_aligned_pawns(x, y, player):
                    if count >= 5:
                        return True
        return False

    def minmax_alpha_beta(self, depth, alpha, beta, maximizing_player, move):
        if depth == 0 or self.is_finished() or time() - self.time >= 4.8:
            return self.evaluate_position(*move, depth)

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
        self.time = time()

        adj_coords = self.find_adjacent_coordinates()
        for x, y in adj_coords:
            if time() - self.time >= 4.8:
                break
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
