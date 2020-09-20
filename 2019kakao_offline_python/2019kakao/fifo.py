import requests


url = 'http://localhost:8000'


def start(user, problem, count):
    uri = url + '/start' + '/' + user + '/' + str(problem) + '/' + str(count)
    return requests.post(uri).json()


def oncalls(token):
    uri = url + '/oncalls'
    return requests.get(uri, headers={'X-Auth-Token': token}).json()


def action(token, cmds):
    uri = url + '/action'
    return requests.post(uri, headers={'X-Auth-Token': token}, json={'commands': cmds}).json()


# def move(token, elev_id, st, end):
#     onc = oncalls(token)
#     for i in range(onc['elevators'][elev_id]['floor'], st):
#         onc = oncalls(token)
#         if onc['elevators'][elev_id]['floor'] > st:
#             a = action(token, [{'elevator_id': elev_id, 'command': 'DOWN'}])
#         elif onc['elevators'][elev_id]['floor'] < st:
#             a = action(token, [{'elevator_id': elev_id, 'command': 'UP'}])
#         print(a['elevators'][elev_id]['floor'])
#
#     onc['calls']

def p0_simulator():
    user = 'test'
    problem = 1
    count = 1

    ret = start(user, problem, count)
    token = ret['token']
    # print('Token for %s is %s' % (user, token))
    onc = oncalls(token)
    while oncalls(token)['is_end'] is False:
        onc = oncalls(token)

        if onc['elevators'][0]['floor'] < onc['calls'][0]['start']:
            for i in range(onc['elevators'][0]['floor'], onc['calls'][0]['start']):
                onc = oncalls(token)
                a = action(token, [{'elevator_id': 0, 'command': 'UP'}])
                # print(a['elevators'][0]['floor'])
        elif onc['elevators'][0]['floor'] > onc['calls'][0]['start']:
            for i in range(onc['elevators'][0]['floor'], onc['calls'][0]['start'], -1):
                onc = oncalls(token)
                a = action(token, [{'elevator_id': 0, 'command': 'DOWN'}])
                # print(a['elevators'][0]['floor'])

        onc = oncalls(token)
        pid = onc['calls'][0]['id']
        # print(onc['elevators'][0]['floor'])
        # print(pid)
        action(token, [{'elevator_id': 0, 'command': 'STOP'}])
        action(token, [{'elevator_id': 0, 'command': 'OPEN'}])
        action(token, [{'elevator_id': 0, 'command': 'ENTER', 'call_ids': [pid]}])
        action(token, [{'elevator_id': 0, 'command': 'CLOSE'}])

        onc = oncalls(token)

        if onc['elevators'][0]['floor'] < onc['elevators'][0]['passengers'][0]['end']:
            for i in range(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'][0]['end']):
                onc = oncalls(token)
                a = action(token, [{'elevator_id': 0, 'command': 'UP'}])
                # print(a['elevators'][0]['floor'])
        elif onc['elevators'][0]['floor'] > onc['elevators'][0]['passengers'][0]['end']:
            for i in range(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'][0]['end'], -1):
                onc = oncalls(token)
                a = action(token, [{'elevator_id': 0, 'command': 'DOWN'}])
                # print(a['elevators'][0]['floor'])

        onc = oncalls(token)
        # print(onc)

        action(token, [{'elevator_id': 0, 'command': 'STOP'}])
        action(token, [{'elevator_id': 0, 'command': 'OPEN'}])
        action(token, [{'elevator_id': 0, 'command': 'EXIT', 'call_ids': [pid]}])
        action(token, [{'elevator_id': 0, 'command': 'CLOSE'}])


if __name__ == '__main__':
    p0_simulator()
