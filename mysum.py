import numpy as np

num_points = 200

def my_sum(sig):
    if len(sig) != num_points:
        return "length_not_correct"
    v = np.sum(sig)
    return v
