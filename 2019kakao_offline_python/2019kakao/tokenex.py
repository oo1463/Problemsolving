import requests


url = 'http://localhost:8000'


def start(user, pid, num_elev):
    url_start = url + '/start/' + user + '/' + str(pid) + '/' + str(num_elev)
    return requests.post(url_start).json()


def oncall(token):
    url_oncall = url + '/oncalls'
    return requests.get(url_oncall, headers={'X-Auth-Token': token}).json()


def act(token, command):
    act_url = url + '/action'
    return requests.post(act_url, headers={'X-Auth-Token': token}, json={'commands': command}).json()


def up(e_id):
    return [{"elevator_id": e_id, "command": "UP"}]


def down(e_id):
    return [{"elevator_id": e_id, "command": "DOWN"}]


def p0():
    user = 'sss'
    pid = 0
    num_elev = 1
    ret = start(user, pid, num_elev)

    token = ret['token']
    on = oncall(token)
    print(on['timestamp'])
    act(token,  up(0))

    on = oncall(token)
    print(on['elevators'][0])


if __name__ == '__main__':
    p0()
