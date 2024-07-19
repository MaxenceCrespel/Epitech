const UserActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const RoleActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const GroupActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const PermissionsActions = {
  READ: 1 << 0,
  UPDATE: 1 << 1,
};

const AppletActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const ActionsActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const ReactionsActions = {
  CREATE: 1 << 0,
  READ: 1 << 1,
  UPDATE: 1 << 2,
  DELETE: 1 << 3,
};

const LogActions = {
  READ: 1 << 0,
  DELETE: 1 << 1,
};

const StatActions = {
  READ: 1 << 0,
};

export interface IPermissions {
  USER: typeof UserActions,
  ROLE: typeof RoleActions,
  GROUP: typeof GroupActions,
  PERMISSIONS: typeof PermissionsActions,
  APPLET: typeof AppletActions,
  ACTIONS: typeof ActionsActions,
  REACTIONS: typeof ReactionsActions,
  LOG: typeof LogActions,
  STAT: typeof StatActions,
  ADMIN: number,
}

const PermissionsList = {
  USER: UserActions,
  ROLE: RoleActions,
  GROUP: GroupActions,
  PERMISSIONS: PermissionsActions,
  APPLET: AppletActions,
  ACTIONS: ActionsActions,
  REACTIONS: ReactionsActions,
  LOG: LogActions,
  STAT: StatActions,
  ADMIN : 5 << 0,

};

export default PermissionsList;