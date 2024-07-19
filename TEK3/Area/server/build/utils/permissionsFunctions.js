"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.hasAllPermissions = exports.hasAnyPermission = exports.hasPermission = exports.removePermission = exports.addPermission = void 0;
function addPermission(userPerms, perm) {
    return userPerms | perm;
}
exports.addPermission = addPermission;
function removePermission(userPerms, perm) {
    return userPerms & ~perm;
}
exports.removePermission = removePermission;
function hasPermission(userPerms, perm) {
    return (userPerms & perm) === perm;
}
exports.hasPermission = hasPermission;
function hasAnyPermission(userPerms, perms) {
    return perms.some((perm) => hasPermission(userPerms, perm));
}
exports.hasAnyPermission = hasAnyPermission;
function hasAllPermissions(userPerms, perms) {
    return perms.every((perm) => hasPermission(userPerms, perm));
}
exports.hasAllPermissions = hasAllPermissions;
