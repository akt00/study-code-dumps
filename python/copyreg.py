import pickle
import copyreg


class GameState:
    def __init__(self, level=0, lives=4, points=0, magic=5):
        self.level = level
        self.lives = lives
        self.points = points
        self.magic = magic


def main1():
    gs = GameState()
    gs.level += 1
    gs.lives += 1
    gs.points += 1

    with open('gs.pkl', 'wb') as f:
        s = pickle.dumps(gs)
        f.write(s)


def pickle_gs(gs):
    kwargs = gs.__dict__
    return unpickle_gs, (kwargs, )


def unpickle_gs(kwargs: dict):
    return GameState(**kwargs)


if __name__ == '__main__':
    copyreg.pickle(GameState, pickle_gs)
    # main1()
    with open('gs.pkl', 'rb') as f:
        res = pickle.load(f)
        print(res.__dict__)
