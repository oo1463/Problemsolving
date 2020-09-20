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


def list_exit(token, e_id):
    on = oncalls(token)
    elev = on['elevators'][e_id]
    li_p = []
    for j in elev['passengers']:
        if j['end'] == elev['floor']:
            li_p.append(j['id'])
    return li_p


def list_enter(token, e_id):
    on = oncalls(token)
    elev = on['elevators'][e_id]
    li_c = []
    for j in on['calls']:
        if j['start'] == elev['floor'] and j['end'] <= elev['floor'] and len(elev['passengers']) + len(li_c) < 8:
            li_c.append(j['id'])
    return li_c


def p2_simulator():
    user = 'test'
    problem = 2
    count = 1

    ret = start(user, problem, count)
    token = ret['token']
    # print('Token for %s is %s' % (user, token))
    onc = oncalls(token)
    elev = onc['elevators'][0]

    while not onc['is_end']:

        for i in range(elev['floor']):  # first 1층으로 내림
            onc = oncalls(token)
            elev = onc['elevators'][0]
            li_p = []
            li_c = []
            for j in elev['passengers']:
                if j['end'] == elev['floor']:
                    li_p.append(j['id'])

            for j in onc['calls']:
                if j['start'] == elev['floor'] and j['end'] <= elev['floor'] and len(elev['passengers'])-len(li_p) + len(li_c) < 8:
                    li_c.append(j['id'])

            if not not li_p or not not li_c:
                action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
                action(token, [{'elevator_id': elev['id'], 'command': 'OPEN'}])
                if not not li_p:
                    action(token, [{'elevator_id': elev['id'], 'command': 'EXIT', 'call_ids': li_p}])
                if not not li_c:
                    action(token, [{'elevator_id': elev['id'], 'command': 'ENTER', 'call_ids': li_c}])
                action(token, [{'elevator_id': elev['id'], 'command': 'CLOSE'}])

            action(token, [{'elevator_id': elev['id'], 'command': 'DOWN'}])
            print(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'])

        action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
        onc = oncalls(token)

        for i in range(26 - elev['floor']):  # second 25층으로 올림
            onc = oncalls(token)
            elev = onc['elevators'][0]
            li_p = []
            li_c = []
            for j in elev['passengers']:
                if j['end'] == elev['floor']:
                    li_p.append(j['id'])

            for j in onc['calls']:
                if j['start'] == elev['floor'] and j['end'] >= elev['floor'] and len(elev['passengers']) - len(li_p) + len(li_c) < 8:
                    li_c.append(j['id'])

            if not not li_p or not not li_c:
                action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
                action(token, [{'elevator_id': elev['id'], 'command': 'OPEN'}])
                if not not li_p:
                    action(token, [{'elevator_id': elev['id'], 'command': 'EXIT', 'call_ids': li_p}])
                if not not li_c:
                    action(token, [{'elevator_id': elev['id'], 'command': 'ENTER', 'call_ids': li_c}])
                action(token, [{'elevator_id': elev['id'], 'command': 'CLOSE'}])

            action(token, [{'elevator_id': elev['id'], 'command': 'UP'}])
            print(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'])

        action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])


if __name__ == '__main__':
    p2_simulator()

