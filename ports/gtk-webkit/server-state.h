/*
Copyright © 2018-2019 Atlas Engineer LLC.
Use of this file is governed by the license that can be found in LICENSE.
*/
#pragma once

// This is kept outside of server.h because window.h also needs it.
#define PLATFORM_PORT_NAME "engineer.atlas.next.platform"
#define PLATFORM_PORT_OBJECT "/engineer/atlas/next/platform" // TODO: Rename to OBJECT_PATH
#define PLATFORM_PORT_INTERFACE PLATFORM_PORT_NAME

#define CORE_NAME "engineer.atlas.next.core"
#define CORE_OBJECT "/engineer/atlas/next/core" // TODO: Rename to CORE_OBJECT_PATH
#define CORE_INTERFACE CORE_NAME

typedef struct {
	GHashTable *windows;
	GHashTable *buffers;
	GHashTable *server_callbacks;
	GDBusConnection *connection;
	const gchar *introspection_xml;
} ServerState;

static ServerState state = {
	/* Introspection data for the service we are exporting */
	.introspection_xml =
		"<node>"
		"  <interface name='engineer.atlas.next.platform'>"
		"    <method name='window_make'>"
		"      <arg type='s' name='id' direction='in'/>"
		"      <arg type='s' name='new_id' direction='out'/>"
		"    </method>"
		"    <method name='window_set_title'>"
		"      <arg type='s' name='id' direction='in'/>"
		"      <arg type='s' name='title' direction='in'/>"
		"      <arg type='b' name='status' direction='out'/>"
		"    </method>"
		"    <method name='window_active'>"
		"      <arg type='s' name='id' direction='out'/>"
		"    </method>"
		"    <method name='window_set_active_buffer'>"
		"      <arg type='s' name='window_id' direction='in'/>"
		"      <arg type='s' name='buffer_id' direction='in'/>"
		"      <arg type='b' name='status' direction='out'/>"
		"    </method>"
		"    <method name='window_set_minibuffer_height'>"
		"      <arg type='s' name='window_id' direction='in'/>"
		"      <arg type='i' name='height' direction='in'/>"
		"      <arg type='i' name='new_height' direction='out'/>"
		"    </method>"
		"    <method name='buffer_make'>"
		"      <arg type='s' name='id' direction='in'/>"
	        /* "      <arg type='a' name='options' direction='in'/>" */
		"      <arg type='s' name='new_id' direction='out'/>"
		"    </method>"
		"    <method name='buffer_load'>"
		"      <arg type='s' name='buffer_id' direction='in'/>"
		"      <arg type='s' name='uri' direction='in'/>"
		"      <arg type='b' name='status' direction='out'/>"
		"    </method>"
		"    <method name='buffer_evaluate_javascript'>"
		"      <arg type='s' name='buffer_id' direction='in'/>"
		"      <arg type='s' name='javascript' direction='in'/>"
		"      <arg type='s' name='callback_id' direction='out'/>"
		"    </method>"
		"    <method name='minibuffer_evaluate_javascript'>"
		"      <arg type='s' name='window_id' direction='in'/>"
		"      <arg type='s' name='javascript' direction='in'/>"
		"      <arg type='s' name='callback_id' direction='out'/>"
		"    </method>"
		"  </interface>"
		"</node>"
};
