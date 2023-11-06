import json


class JsonMixin:
    @classmethod
    def from_json(cls, data):
        kwargs = json.loads(data)
        return cls(**kwargs)

    def to_json(self):
        assert hasattr(self, 'to_dict') and callable(getattr(self, 'to_dict'))
        return json.dumps(self.to_dict())


class ToDictMixin:
    def to_dict(self):
        assert hasattr(self, '_traverse_dict') and callable(getattr(self, '_traverse_dict'))
        return self._traverse_dict(self.__dict__)

    def _traverse_dict(self, instance_dict):
        output = {}
        for k, v in instance_dict.items():
            output[k] = self._traverse(k, v)
        return output

    def _traverse(self, k, v):
        if isinstance(v, ToDictMixin):
            return v.to_dict()
        elif isinstance(v, dict):
            return self._traverse_dict(v)
        else:
            return v


class Machine(ToDictMixin, JsonMixin):
    def __init__(self, cores=None, ram=None, disk=None):
        self.cores = cores
        self.ram = ram
        self.disk = disk


m = Machine()
print(m.to_dict())
