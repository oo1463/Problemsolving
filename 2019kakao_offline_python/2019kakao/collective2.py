import requests


url = 'http://localhost:8000'
q0 = []
q1 = []
q = [q0, q1]
visited = []


def start(user, problem, count):
    uri = url + '/start' + '/' + user + '/' + str(problem) + '/' + str(count)
    return requests.post(uri).json()


def oncalls(token):
    uri = url + '/oncalls'
    return requests.get(uri, headers={'X-Auth-Token': token}).json()


def action(token, cmds):
    uri = url + '/action'
    return requests.post(uri, headers={'X-Auth-Token': token}, json={'commands': cmds}).json()


def list_exit(on, e_id):
    elev = on['elevators'][e_id]
    li_p = []
    for j in elev['passengers']:
        if j['end'] == elev['floor']:
            li_p.append(j['id'])
    return li_p


def list_enter(on, e_id):
    elev = on['elevators'][e_id]
    li_c = []
    for j in on['calls']:
        if j['start'] == elev['floor'] and len(elev['passengers']) + len(li_c) < 8 and j['id'] not in visited:
            li_c.append(j['id'])
            visited.append(j['id'])
            print(visited)

    return li_c


def p2_simulator():
    user = 'test'
    problem = 1
    count = 2

    ret = start(user, problem, count)
    token = ret['token']
    # print('Token for %s is %s' % (user, token))
    onc = oncalls(token)
    elev0 = onc['elevators'][0]
    elev1 = onc['elevators'][1]

    while not onc['is_end']:

        onc = oncalls(token)
        elev0 = onc['elevators'][0]
        elev1 = onc['elevators'][1]
        now_call = onc['calls']

        li_ex0 = []
        li_en0 = []

        li_ex1 = []
        li_en1 = []

        if not q0:
            li_ex0 = list_exit(onc, 0)
            li_en0 = list_enter(onc, 0)

            if not not li_ex0 or not not li_en0:
                q0.append({'elevator_id': 0, 'command': 'STOP'})
                q0.append({'elevator_id': 0, 'command': 'OPEN'})
                if not not li_ex0:
                    q0.append({'elevator_id': 0, 'command': 'EXIT', 'call_ids': li_ex0})
                if not not li_en0:
                    q0.append({'elevator_id': 0, 'command': 'ENTER', 'call_ids': li_en0})
                q0.append({'elevator_id': 0, 'command': 'CLOSE'})

            if elev0['status'] == 'DOWNWARD' and elev0['floor'] != 1:
                q0.append({'elevator_id': 0, 'command': 'DOWN'})
            elif elev0['status'] == 'UPWARD' and elev0['floor'] != 25:
                q0.append({'elevator_id': 0, 'command': 'UP'})

        if not q0 and elev0['floor'] == 25:
            q0.append({'elevator_id': 0, 'command': 'STOP'})
            q0.append({'elevator_id': 0, 'command': 'DOWN'})
        elif not q0 and elev0['floor'] == 1:
            q0.append({'elevator_id': 0, 'command': 'STOP'})
            q0.append({'elevator_id': 0, 'command': 'UP'})

        if not q1:
            li_ex1 = list_exit(onc, 1)
            if elev0['floor'] != elev1['floor']:
                li_en1 = list_enter(onc, 1)
            if not not li_ex1 or not not li_en1:
                q1.append({'elevator_id': 1, 'command': 'STOP'})
                q1.append({'elevator_id': 1, 'command': 'OPEN'})
                if not not li_ex1:
                    q1.append({'elevator_id': 1, 'command': 'EXIT', 'call_ids': li_ex1})
                if not not li_en1:
                    q1.append({'elevator_id': 1, 'command': 'ENTER', 'call_ids': li_en1})
                q1.append({'elevator_id': 1, 'command': 'CLOSE'})

            if elev1['status'] == 'DOWNWARD' and elev1['floor'] != 1:
                q1.append({'elevator_id': 1, 'command': 'DOWN'})
            elif elev1['status'] == 'UPWARD' and elev1['floor'] != 25:
                q1.append({'elevator_id': 1, 'command': 'UP'})

        if not q1 and elev1['floor'] == 25:
            q1.append({'elevator_id': 1, 'command': 'STOP'})
            q1.append({'elevator_id': 1, 'command': 'DOWN'})
        elif not q1 and elev1['floor'] == 1:
            q1.append({'elevator_id': 1, 'command': 'STOP'})
            q1.append({'elevator_id': 1, 'command': 'UP'})

        # print(elev0['passengers'], elev1['passengers'])
        # print(q0[0], q1[0])
        # print(onc['calls'])
        action(token, [q0[0], q1[0]])
        del q0[0]
        del q1[0]


if __name__ == '__main__':
    p2_simulator()


# for i in range(elev['floor']):  # first 1층으로 내림
#     onc = oncalls(token)
#     elev = onc['elevators'][0]
#     li_p = []
#     li_c = []
#     for j in elev['passengers']:
#         if j['end'] == elev['floor']:
#             li_p.append(j['id'])
#
#     for j in onc['calls']:
#         if j['start'] == elev['floor'] and j['end'] <= elev['floor'] and len(elev['passengers']) - len(li_p) + len(
#                 li_c) < 8:
#             li_c.append(j['id'])
#
#     if not not li_p or not not li_c:
#         action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
#         action(token, [{'elevator_id': elev['id'], 'command': 'OPEN'}])
#         if not not li_p:
#             action(token, [{'elevator_id': elev['id'], 'command': 'EXIT', 'call_ids': li_p}])
#         if not not li_c:
#             action(token, [{'elevator_id': elev['id'], 'command': 'ENTER', 'call_ids': li_c}])
#         action(token, [{'elevator_id': elev['id'], 'command': 'CLOSE'}])
#
#     action(token, [{'elevator_id': elev['id'], 'command': 'DOWN'}])
#     print(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'])
#
# action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
# onc = oncalls(token)
#
# for i in range(26 - elev['floor']):  # second 25층으로 올림
#     onc = oncalls(token)
#     elev = onc['elevators'][0]
#     li_p = []
#     li_c = []
#     for j in elev['passengers']:
#         if j['end'] == elev['floor']:
#             li_p.append(j['id'])
#
#     for j in onc['calls']:
#         if j['start'] == elev['floor'] and j['end'] >= elev['floor'] and len(elev['passengers']) - len(li_p) + len(
#                 li_c) < 8:
#             li_c.append(j['id'])
#
#     if not not li_p or not not li_c:
#         action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])
#         action(token, [{'elevator_id': elev['id'], 'command': 'OPEN'}])
#         if not not li_p:
#             action(token, [{'elevator_id': elev['id'], 'command': 'EXIT', 'call_ids': li_p}])
#         if not not li_c:
#             action(token, [{'elevator_id': elev['id'], 'command': 'ENTER', 'call_ids': li_c}])
#         action(token, [{'elevator_id': elev['id'], 'command': 'CLOSE'}])
#
#     action(token, [{'elevator_id': elev['id'], 'command': 'UP'}])
#     print(onc['elevators'][0]['floor'], onc['elevators'][0]['passengers'])
#
# action(token, [{'elevator_id': elev['id'], 'command': 'STOP'}])

