function addPermission(userPerms:number, perm:number):number {
    return userPerms | perm;
}

function removePermission(userPerms:number, perm:number):number {
    return userPerms & ~perm;
}

function hasPermission(userPerms:number, perm:number):boolean {
    return (userPerms & perm) === perm;
}

function hasAnyPermission(userPerms:number, perms:number[]):boolean {
    return perms.some((perm) => hasPermission(userPerms, perm));
}

function hasAllPermissions(userPerms:number, perms:number[]):boolean {
    return perms.every((perm) => hasPermission(userPerms, perm));
}

export {
    addPermission,
    removePermission,
    hasPermission,
    hasAnyPermission,
    hasAllPermissions,
};